docker rm -f csapp

docker run -it \
           --name csapp \
           -v /Users/yeer/go/src/github.com/athom/playthings/csapp-homework/labs:/data/labs \
           yeer/csapp

