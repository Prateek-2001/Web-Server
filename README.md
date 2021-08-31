# Web Server

## Project Description

In this project, I shall be implementing a Web Server using C. 

## Goal

Make my own Web Server and put it into production which shall be able to Host any website I create

## Description

### What is a web server?

A web server is a piece of software that accepts HTTP requests (e.g. GET requests for HTML pages), and returns responses (e.g. HTML pages). Other common uses are GET requests for getting data from RESTful API endpoints, images within web pages, and POST requests to upload data to the server (e.g. a form submission or file upload).

## Specifications

1. Get a basic TCP sockets layer running (listen on port/ports, accept client connections and send/receive data). <br/>
2. Implement a buffered reader so that it can read requests one line (delimited by CRLF) at a time. <br/>
3. Read the very first line. Parse out the method, the request version and the path. <br/>
4. Implement header parsing for the "Header: value" syntax. Don't forget unfolding folded headers. <br/>
5. Check the request method, content type and content size to determine how/if the body will be read. <br/>
6. Implement decoding of content based on content type. <br/>
7. If it is going to support HTTP 1.1, implement things like "100 Continue", keep-alive, chunked transfer. <br/>
8. Add robustness/security measures like detecting incomplete requests, limiting max number of clients etc. <br/>
