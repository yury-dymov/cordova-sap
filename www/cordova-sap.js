sapHelloWorld: function() {
  cordova.exec(function(res) { console.log(res)}, null, 'CDVSap', 'sapHelloWorld');   
}