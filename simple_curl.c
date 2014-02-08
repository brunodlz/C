/*
 * Muito interessante ...
 * Com certeza vale apena estudar curl/libcurl
 *
 * compile: gcc -Wall -g simple_curl.c -lcurl -o binprog; ./binprog
 *
 * http://curl.haxx.se/libcurl/c/simple.html
 * http://curl.haxx.se/libcurl/c/libcurl-tutorial.html
*/

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main() {
 CURL *curl;
 CURLcode res;

 curl = curl_easy_init();
 if(curl) {
  curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION,1L);
  res = curl_easy_perform(curl);
  if(res != CURLE_OK)
   fprintf(stderr,"curl_easy_perform() failed: %s\n",curl_easy_strerror(res));

  curl_easy_cleanup(curl);
 }
 return 0;
}
