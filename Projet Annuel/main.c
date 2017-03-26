//
//  main.c
//  Projet Annuel
//
//  Created by Axel Noiret on 25/03/2017.
//  Copyright © 2017 Axel Noiret. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main (){
    
    
    //http://api.openweathermap.org/data/2.5/weather?q=Evreux,fr&appid=1480331759b8687b28f5ca6e11bf04a9
    
    CURL *session = curl_easy_init();
    
    curl_easy_setopt(session, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?q=Evreux,fr&appid=1480331759b8687b28f5ca6e11bf04a9");
    
    FILE * fp = fopen("./index_ccm.html", "w"); //Création de notre fichier
    curl_easy_setopt(session,  CURLOPT_WRITEDATA, fp); //On balance notre pointeur de fichier comme destination
    curl_easy_setopt(session,  CURLOPT_WRITEFUNCTION, fwrite);
    
    curl_easy_perform(session);
    fclose(fp);
    curl_easy_cleanup(session);
    
    return 0;
}
