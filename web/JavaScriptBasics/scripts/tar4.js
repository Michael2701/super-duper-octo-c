'use strict';

function get_real_numbers(number){
    const numbers = [];

    for(let i = number; i > 2 ; i--){
        let flag = true;
        
        if(i%2 == 0) flag = false;
        
        if(flag){
            for(let j = i - 1; j > 2; j--){
                if( i % j == 0 ) flag = false;
            }
        }
    
        if(flag){
            numbers.push(i);
        }
    }

    return numbers;
}

document.querySelector('#refresh').addEventListener('click', function(e){
    location.reload();
});
let number = parseInt(prompt("Please enter a number"));
const numbers = get_real_numbers(number);


console.log(numbers);

let index = 1;
const container = document.getElementById('container');
const timeout = setInterval(function(){
    container.innerText = (numbers.slice(0, index)).join(', ');
    if(index >= numbers.length){
        clearInterval(timeout);
    }else{
        index++;
    }
},500);









