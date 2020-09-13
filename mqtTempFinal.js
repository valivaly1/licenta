var mqtt=require('mqtt');
fs = require('fs');
var client = mqtt.connect("mqtt://141.85.176.16:1883",{username:'NodeRedUser'})
var topic = 'Temp/#'
var string;
client.on("connect",function(){
console.log("connected");
})
client.on('connect', () => {
  client.subscribe(topic)
})
var dacanue4='0000'
client.on('message',(topic,message)=>{
    string = message.toString()
    console.log(message.toString())
    console.log(string)
    var t1 = string.substring(string.lastIndexOf('T_1":"')+6,string.lastIndexOf$
    console.log(t1)
    var tt1 = Number(t1)*10
