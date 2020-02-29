'use strict';

class Tragil3{
    num; str;
    main(){
        this.inputNumber();
        if(this.isNumber()){
            this.strReverse();
            alert(this.str);
        }
    }
    inputNumber(){
        do{
            this.num = prompt('Please enter a number');
        }while(isNaN(this.num) && !isFinite(this.num));
    }
    isNumber(){
        const num = Number(this.num);
        return Number.isInteger(num);
    }
    strReverse(){
        this.str =  this.num.split('').reverse().join('');
    }
    numReverse(){
        let res = 0;
        let num = parseInt(this.num);
        while(num){
            res *= 10;
            res += num%10;
            num =  parseInt(num/10);
        }
        alert(res);
    }
}

const t3 = new Tragil3();
t3.main();
t3.numReverse();