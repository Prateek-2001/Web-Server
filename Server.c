#include<winsock2.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int init()
{
 WSADATA wsaData;
 int iResult;

 iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
 if (iResult != 0) 
 {
  printf("WSAStartup failed: %d\n", iResult);
  return 1;
 }

}

void server()
{
 
        int sock, connected, bytes_recieved ;  
        char send_data [1024] , recv_data[1024], true = 1;       

        struct sockaddr_in server_addr,client_addr;    
        int sin_size;
        
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int)) == -1) {
            perror("Setsockopt");
            exit(1);
        }
        
        server_addr.sin_family = AF_INET;         
        server_addr.sin_port = htons(8080);     
        server_addr.sin_addr.s_addr = INADDR_ANY; 
       
 		memset(&(server_addr.sin_zero),0,8);
 		
        if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))== -1) 
   		 {
            perror("Unable to bind");
            exit(1);
        }

        if (listen(sock, 5) == -1) 
 		 {
            perror("Listen");
            exit(1);
        }
  
  		printf("\nPrateek's Server is waiting on port 8080");
        fflush(stdout);
        

            sin_size = sizeof(struct sockaddr_in);

            connected = accept(sock, (struct sockaddr *)&client_addr,&sin_size);


   char kk[1000];
   recv(connected,kk,sizeof(kk),0);
   printf("\n Received:%s",kk); 
   
   char body[1000];
   strcpy(body,"HTTP/1.1 200 OK\nContent-length: 300\nContent-Type: text/html\n\n<html><body><center><h1>Welcome to Prateek's Server</h1><h3>Made by <a href='https://github.com/Prateek-2001/Web-Server'>Prateek Pradhan</a></h3><p> This web server has been implemented using C </p><p>The Web Server supports HTML, CSS and JavaScript</p><br></center></body></html>");
   
   int c = send(connected, body, sizeof(body), 0);
   
   printf("\nSTATUS:%d",c);
     
   printf("\nSent : %s\n",body);
   
            close(sock);
   WSACleanup();
}


void clean()
{
 WSACleanup();
}
int main()
{


 while(1)
 {
  init();
  server();
  clean();
 }
  
    return 0;
} 

