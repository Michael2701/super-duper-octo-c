'use strict';

let message;
let str = prompt("Please enter A, B or C");

switch(str.trim()){
    case 'A':
        message = 'A is good';
    break;
    case 'B':
        message = 'B is great';

    break;
    case 'C':
        message = 'C is the big one';

    break;
    default:
        message = 'Your letter is pritty';
}

alert(message);
