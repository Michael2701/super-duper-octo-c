import { Component, OnInit, ViewChild, Output, EventEmitter } from '@angular/core';
import { Ingredient } from 'src/app/shared/ingredient.model';

@Component({
  selector: 'app-shopping-list-edit',
  templateUrl: './shopping-list-edit.component.html',
  styleUrls: ['./shopping-list-edit.component.scss']
})
export class ShoppingListEditComponent implements OnInit {
  newIngredient: Ingredient;
  @Output() ingredientCreated = new EventEmitter<Ingredient>();
  @ViewChild('nameInput', {static: false}) nameInput: HTMLInputElement;
  @ViewChild('amountInput', {static: false}) amountInput: HTMLInputElement;

  constructor() { }

  ngOnInit(): void {
  }

  onSubmit(){
    this.newIngredient = new Ingredient(
      this.nameInput['nativeElement'].value, 
      +this.amountInput['nativeElement'].value 
    );
    
    this.ingredientCreated.emit(this.newIngredient);
  }
}
