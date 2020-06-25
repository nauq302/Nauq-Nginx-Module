# Nauq-Nginx-Module
My Nginx Module just for learning

Build:
  Recompile Nginx with path to folder contains 'config' file:
  
    ./configure --add-module=/path/to/folder/contains/config_file
    
example
  Create a Nginx file look like:
  
    events {
    }

    http {
        server {
            server_name localhost;
            listen 80;

            location / {
                nauq_print "Ahihi";
            }
        }
    }
    
  Or you can run the 'demo.nginx' file.
