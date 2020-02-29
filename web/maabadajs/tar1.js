'use strict';
// var str = buildTable();
// document.write(str);

// targil 1
function foo(){
    for(let i = 0; i < arguments.length; i++){
        console.log(arguments[i]);
    }
}
let j = 3;
while(j){
    foo('qwe',123,{a:"Hello world"}, [1,2,3,4,5], typeof null);
    j--;
}









