'use strict';

let num1, num2;

do{
    num1 = prompt('Please enter first number');
    parseFloat(num1);
}while(isNaN(num1) && !isFinite(num1));

do{
    num2 = prompt('Please enter second number');
    parseFloat(num2);
}while(isNaN(num2) && !isFinite(num2));

console.log(num1**num2);






