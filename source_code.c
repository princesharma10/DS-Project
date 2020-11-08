/*
***********DS Project***************** 
   Team Members:
   Prince Sharma (2K19/CO/295)
   Purshottam Kumar (2K19/CO/295)
**************************************
*/
#include<stdio.h>
#define size 30
//define the size of the stack
struct mystack{
      int arr[size];   //for storing the count of spaces in it.
      int t;   //for top element of the stack 
};
//gave the name pr of mystack
typedef struct mystack pr;
//make a pop function 
void pop(pr *h){
    if(h->t == -1){  //if stack is empty return 
        return;
    }
    //otherwise
    h->t = h->t - 1;  
}
//make a push function 
void push(pr *h,int temp){
   if(h->t == size){  //if size of the stack is full then return 
       return;  
   }
   h->t = h->t +1;
   h->arr[h->t] = temp;  //here putting the count in the array 
}

//deifne a main function 
int main(){
   printf("Enter the file name in .txt format: ");
   char name[1000]; //making array for storing the file name 
   gets(name);  //reading the file name 
   FILE *fp; //declare a file pointer variable 
   fp = fopen(name,"r"); //r - opens in read mode  and sets pointer to the first character in the file. It returns null if file does not exist.
  if(fp==NULL){
      printf("File name you entered doesn't exist");
      return 0;
  }
  char cr;
  cr = fgetc(fp);
  printf("File Content: \n\n");
  while(cr!= EOF){     //EOF refers to the end of the file 
      printf("%c",cr);
      cr = fgetc(fp);   //fgetc() is used to obtain input from a file single character at a time. This function returns the number of characters read by function .
  }
  rewind(fp);   //the rewind function sets the file position to the beginning of the file for the stream. It also clears the error and end of file indicators for stream.
 printf("\n");
 int count =0;
 int line =1;
 pr h;
 h.t = -1; //t refers to top element of the stack 
 printf("Checking Indentation...\n\n");    //now printing checking Indentation 
 int flag = -1;
 while((cr = fgetc(fp))!=EOF){ 
     //reading space of the line 
     if(cr=='\t' && flag == -1){
         count += 8;
     }
     else if (cr==' ' && flag == -1){
         count++;
     }
     else if (cr=='\n'){
         if(h.t == -1){
             push(&h,count);  //calling the push function 
         }
         else{
             if((h.arr[h.t])< count){
                 push(&h,count);  //calling the push function 
             }
            else if (count <(h.arr[h.t])){
             pop(&h);  //calling the pop function 
             if(h.t!=-1 && h.arr[h.t]!= count){
                printf("Error at line %d, not properly indented",line);
				return 0;
             }
         }
         }
        
     
     count = 0;
     line++; //increase the line 
     flag = -1;
     }
     else{
         flag = 1;
     }
 }
 pop(&h);
 //if we get similar value of count and the element at the top then file is ok 
 if(h.t!=-1 && count == h.arr[h.t] && flag ==1){
     printf("\nfile is OK");	
		return 0;
 }
 //if we didn't get similar value of count and the element at the top then we print that line and print file is not properly indented 
else{
		printf("Error at line %d, not properly indented",line);
	}
	fclose(fp);  //close th stream


    return 0;
}
