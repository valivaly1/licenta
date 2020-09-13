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
    var t1 = string.substring(string.lastIndexOf('T_1":"')+6,string.lastIndexOf('T_1":"')+10)
    console.log(t1)
    var tt1 = Number(t1)*10
    console.log(tt1)
    ht1=tt1.toString(16)
    if(ht1.length < 4){
            var tmp = 4 - ht1.length;
            var stmp = dacanue4.substring(0,tmp);
            ht1f = stmp.concat(ht1).toUpperCase();
        }
        else{ht1f=ht1.toUpperCase()}
    console.log(ht1f)
    fs.writeFile('temp.txt',ht1f,function (err){
     if(err) return console.log(err);
     console.log('a scris');
})
})
