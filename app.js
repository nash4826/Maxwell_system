const express = require("express");
const bodyParser = require("body-parser");
const request = require("request");
const https = require("https");
const app = express();

app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static("public"));
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'html');

app.get("/",function(req,res){
  res.render('index');
});

app.get('/state.html',function(req,res){
  res.render('state');
})

app.listen(3000,function(){
  console.log("connecting 3000");
});