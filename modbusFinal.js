var ModbusRTU = require("modbus-serial");
var client = new ModbusRTU();
fs = require('fs');


     client.connectRTUBuffered("/dev/ttyUSB0", { baudRate: 2400 }, read);


async function read() {
    // read the 2 registers starting at address 5
    // on device number 1.
    await client.setID (1);
    while (true)
    {
        var strfinal='000000000000000000000000';
        var dacanue4='0000';
        //freq read and print
        let freq = await client.readInputRegisters(70, 2);
        console.log (freq.buffer.readFloatBE (0));
        var f100 = freq.buffer.readFloatBE (0) * 100;
        var ff100 = Math.trunc(f100);
        var fffs = ff100.toString(16);
        if(fffs.length < 4){
            var tmp = 4 - fffs.length;
            var stmp = dacanue4.substring(0,tmp);
            fffsff = stmp.concat(fffs);
            fffsf = fffsff.toUpperCase();
        }
        else{fffsf = fffs.toUpperCase();}
        //volt read and print
        let volt = await client.readInputRegisters(0, 2);
        console.log (volt.buffer.readFloatBE (0));
        var v100 = volt.buffer.readFloatBE (0) *100;
        var vv100 = Math.trunc(v100);
        var vvvs = vv100.toString(16);
        if(vvvs.length < 4){
            var tmp = 4 - vvvs.length;
            var stmp = dacanue4.substring(0,tmp);
            vvvsff = stmp.concat(vvvs);
                vvvsf=vvvsff.toUpperCase();
        }
        else{vvvsf = vvvs.toUpperCase();}
        //current read and print
        let current = await client.readInputRegisters(6, 2);
        console.log (current.buffer.readFloatBE (0));
        var c100 = current.buffer.readFloatBE (0) *100;
        var cc100 = Math.trunc(c100);
        var cccs = cc100.toString(16);
        if(cccs.length < 4){
            var tmp = 4 - cccs.length;
            var stmp = dacanue4.substring(0,tmp);
            cccsff = stmp.concat(cccs);
cccsf = cccsff.toUpperCase();
        }
        else{cccsf = cccs.toUpperCase();}
        //P read and print
        let putereActiva = await client.readInputRegisters(12, 2);
        console.log (putereActiva.buffer.readFloatBE (0));
        var p100 = putereActiva.buffer.readFloatBE (0) *100;
        var pp100 = Math.trunc(p100);
        var ppps = pp100.toString(16);
        if(ppps.length < 4){
            var tmp = 4 - ppps.length;
            var stmp = dacanue4.substring(0,tmp);
            pppsff = stmp.concat(ppps);
pppsf = pppsff.toUpperCase();
}
        else{pppsf = ppps.toUpperCase();}
        //S read and print
        let putereAparenta = await client.readInputRegisters(18, 2);
        console.log (putereAparenta.buffer.readFloatBE (0));
        var s100 = putereAparenta.buffer.readFloatBE (0) *100;
        var ss100 = Math.trunc(s100);
        var ssss = ss100.toString(16);
        if(ssss.length < 4){
            var tmp = 4 - ssss.length;
            var stmp = dacanue4.substring(0,tmp);
            ssssff = stmp.concat(ssss);
ssssf=ssssff.toUpperCase();
}
        else{ssssf = ssss.toUpperCase();}
        //Q read and print
        let putereReactiva = await client.readInputRegisters(24, 2);
        console.log (putereReactiva.buffer.readFloatBE (0));
        var q100 = putereReactiva.buffer.readFloatBE (0) *100;
        var qq100 = Math.trunc(q100);
var qq1000 = Math.abs(qq100);
 var qqqs = qq1000.toString(16);
        if(qqqs.length < 4){
            var tmp = 4 - qqqs.length;
            var stmp = dacanue4.substring(0,tmp);
            qqqsff = stmp.concat(qqqs);
qqqsf=qqqsff.toUpperCase();
}
        else{qqqsf = qqqs.toUpperCase();}
        strfinal = fffsf + vvvsf + cccsf + pppsf + ssssf + qqqsf;
        console.log(strfinal)
        fs.writeFile('data.txt',strfinal,function (err){
     if(err) return console.log(err);
     console.log('a scris');
 })
        //time out oan a la urmatoarea citire
        await new Promise ((resolve) => setTimeout (resolve, 60000));
    }
}
