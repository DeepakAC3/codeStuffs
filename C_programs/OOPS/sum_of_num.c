#include <stdio.h>
#include <stdlib.h>

typedef struct book_details{
    char *title,*author,*ISBN;
    int pages;
}book_details;

int max_pgs(book_details *,int);

int main(){
    printf("Enter the No. of books: ");
    int no_books;
    scanf("%[^\n]%*c",&no_books);
    
}

