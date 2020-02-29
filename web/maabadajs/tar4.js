'use strict';

class Tragil4{
    num1; num2; html;

    input(){
        do{
            this.num1 = prompt('Please enter a first number');
            this.num1 = parseInt(this.num1);
        }while(
            (isNaN(this.num1) && !isFinite(this.num1)) || 
            this.num1 < 1 || 
            this.num1 > 10
        );

        do{
            this.num2 = prompt('Please enter a second number');
        }while(
            (isNaN(this.num2) && !isFinite(this.num2)) || 
            this.num2 < 1 || 
            this.num2 > 10
        );
    }
    buildTable(){
        this.input();
        this.html = "<table>";

        this.html += "<tr>";
        for(let i = 0; i <= this.num2; i++ ){
            if(i) this.html += "<th>"+i+"</th>";
            else this.html += "<th></th>";
        }
        this.html += "</tr>";


        for(let i = 1; i <= this.num1; i++ ){
            this.html += "<tr>";
            for(let j = 0; j <= this.num2; j++){
                if(j) this.html += "<td>"+i*j+"</td>";
                else this.html += "<td>"+i+"</td>";
            }
            this.html += "</tr>";
        }

        this.html += "</table>";
        document.write(this.html);
    }

}

const t3 = new Tragil4();
t3.buildTable();