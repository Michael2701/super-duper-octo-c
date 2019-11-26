class Parser{
    arr = [];
    flag = true;
    leftPar = ['(', '{', '['];
    rightPar = [')', '}', ']'];

    constructor(str=''){
        this.str = str.split('');
    }

    isLeft(par){
        for(let i = 0; i < 3; i++){
            if(this.leftPar[i] == par){
                return true;
            }
        }
        return false;
    }

    isRight(par){
        for(let i = 0; i < 3; i++){
            if(this.rightPar[i] == par){
                return i;
            }
        }
        return -1;
    }

    setStr(str){
        this.str = [];
        this.arr = [];
        this.flag = true;
        this.str = str.split('');
        return this;
    }

    getStr(){
        return this.str;
    }

    getArr(){
        return this.arr;
    }

    isValid(str)
    {
        this.setStr(str);

        for(let i = 0; i < this.str.length && this.flag; i++)
        {
            let s = this.str[i];
            let right = this.isRight(s);

            if( this.isLeft(s) ){
                this.arr.push(s);
            }

            if( 
                right != -1 &&
                ( this.arr.length == 0 ||
                  this.arr.pop() != this.leftPar[right] )
            ){
                this.flag = false;
            }
        };

        if(this.arr.length > 0)
        {
            this.flag = false;
        }

        return this.flag;
    }
}