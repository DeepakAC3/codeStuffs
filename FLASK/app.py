from flask import Flask
app = Flask(__name__)


#simple routing
@app.route('/') #creates url for the index page
def index():
    return ("this is the deepak pradips's flask application")


@app.route('/about') #there shldnt be a line in between
def about():
    return("this is the about page of deepak pradip")

#vanity url/routing also known as dynamic url
@app.route('/about/<name>') #string written in the url is passed to the function
def author(name):
    return('The name of the author is '+name)

#vanity url v2
@app.route('/author/<name>/<subject>')
def author_with_subject(name,subject):
    return('The name of the Author is '+name+" He reads "+ subject)

if __name__ == '__main__':
    app.run(debug = True,port = 5000)