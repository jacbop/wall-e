Everything so far done in browser. Should pull down here with a publish step.

## Mock bin webserver
Our lambda is going to call out to our ESP-8266 Wifi enabled microcontroller, but we want
a simple mock to validate that the lambda is functioning properly first.
The site `https://requestloggerbin.herokuapp.com` allows us to set up a simple bin so we can GET
or POST to a url and get a 200 back with a predicatble json payload response.

The lambda will `GET https://requestloggerbin.herokuapp.com/bin/6c51e95a-4785-42c6-98ca-99c0f01fecaa`
and we can see the access log at `https://requestloggerbin.herokuapp.com/bin/6c51e95a-4785-42c6-98ca-99c0f01fecaa/log`

We should be able to say 'alexa tell wall-e to grind coffee' and see the activity in the log

## Mock node webserver
The next step is to open a port through our home router and confirm that the lambda can call to a
web server in our home network. We open the port 10605 in our home router and direct traffic to our
development laptop.

We run 
```
npm install http-server -g
http-server -p 10605
```

And we now have a simple http server running that the lambda can invoke on.

```
damme:lambda tom$ http-server -p 10605
Starting up http-server, serving ./
Available on:
  http://127.0.0.1:10605
  http://192.168.1.217:10605
Hit CTRL-C to stop the server
```

We should now be able to say 'alexa tell wall-e to grind coffee' and see the activity in this window

```
damme:lambda tom$ http-server -p 10605
Starting up http-server, serving ./
Available on:
  http://127.0.0.1:10605
  http://192.168.1.217:10605
Hit CTRL-C to stop the server
[Sat Apr 28 2018 16:55:19 GMT-0500 (CDT)] "GET /start.html?17000" "undefined"
```
