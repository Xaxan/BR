
function change_val(val) {
 var select = document.getElementById('select-ha').value;
 var text   = document.getElementById('hiden-value');
 text.value = select;
}

function change_full_val(val) {
 var select = document.getElementById('select-full').value;
 var text   = document.getElementById('full-hiden-value');
 text.value = select;
}


window.onload = function(){ 

document.getElementById("quicktabs-tab-stat-1").onclick = function(e) {
    e = e || event
var target = e.target || e.srcElement
// variable target has your clicked element
    innerId = target.id;
    //  do your stuff here. 
    var text   = document.getElementById('qt-stat');
    text.value = 1;
}

document.getElementById("quicktabs-tab-stat-0").onclick = function(e) {
    e = e || event
var target = e.target || e.srcElement
// variable target has your clicked element
    innerId = target.id;
    //  do your stuff here. 
    var text   = document.getElementById('qt-stat');
    text.value = 0;
 }
 window.scrollTo(0,500); // horizontal and vertical scroll increments
};

function pageScroll() {
    //	window.scrollTo(0,500); // horizontal and vertical scroll increments
    	//scrolldelay = setTimeout('pageScroll()',100); // scrolls every 100 milliseconds
}