from flask import Flask, render_template, url_for, request, jsonify, session, redirect
from flask_oauthlib.client import OAuth
import requests
import werkzeug.urls

app = Flask(__name__)
app.secret_key = 'controlaltdefeat'

google_client_id = "1048536300478-3mupo3uhuajdnh9c951khu0h722do7r1.apps.googleusercontent.com"
google_client_secret = "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"
google_reditrect_uri = "http://localhost:5000/oauth2callback"

oauth = OAuth(app)
google = oauth.remote_app(
    'google',
    consumer_key=google_client_id,
    consumer_secret=google_client_secret,
    request_token_params={
        'scope': 'email',
    },
    base_url='https://www.googleapis.com/oauth2/v1/',
    request_token_url=None,
    access_token_method='POST',
    access_token_url='https://accounts.google.com/o/oauth2/token',
    authorize_url='https://accounts.google.com/o/oauth2/auth',
)

@app.route('/')
def index():
    if 'google_token' in session:
        me = google.get('userinfo')
        return jsonify({'data': me.data})
    return 'Hello! Log in with your Google account: <a href="/login">Log in</a>'

@app.route('/login')
def login():
    return google.authorize(callback=url_for('authorized', _external=True))

@app.route('/login/authorized')
def authorized():
    response = google.authorized_response()
    if response is None or response.get('access_token') is None:
        return 'Login failed.'

    session['google_token'] = (response['access_token'], '')
    me = google.get('userinfo')
    # Here, 'me.data' contains user information.
    # You can perform registration process using this information if needed.

    return redirect(url_for('index'))

@app.route('/logout')
def logout():
    session.pop('google_token', None)
    return redirect(url_for('index'))


@oauth.tokengetter
def get_google_oauth_token():
    return session.get('google_token')


if __name__ == '__main__':
    app.run(debug=True)