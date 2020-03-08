import { Component, OnInit, Output, EventEmitter, OnDestroy, ViewChild } from '@angular/core';
import { Ingredient } from 'src/app/shared/ingredient.model';
import { ShoppingService } from '../shopping.service';
import { NgForm } from '@angular/forms';
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-shopping-list-edit',
  templateUrl: './shopping-list-edit.component.html',
  styleUrls: ['./shopping-list-edit.component.scss']
})
export class ShoppingListEditComponent implements OnInit, OnDestroy {
  @Output() ingredientCreated = new EventEmitter<Ingredient>();
  @ViewChild('form', {static: false}) form: NgForm;
  newIngredient: Ingredient;
  subscription: Subscription;
  editMode = false;
  editedItemId: number;
  editedItem: Ingredient;

  constructor(private shoppingService: ShoppingService) { }

  ngOnInit(): void {
    this.subscription = this.shoppingService.startingEditing.subscribe(
      (id: number) => {
        this.editMode = true;
        this.editedItemId = id;
        this.editedItem = this.shoppingService.getIngredient(id);
        this.form.setValue({
          name: this.editedItem.name,
          amount: this.editedItem.amount,
        })
      }
    );
  }

  onSubmit(form: NgForm){
    this.newIngredient = new Ingredient(
      form.value.name,
      form.value.amount
    );
    if(this.editMode){
      this.shoppingService.updateIngredient(this.editedItemId, this.newIngredient);
    }else{
      this.shoppingService.addIngredient(this.newIngredient);
    }
    this.clearForm();
  }

  clearForm(){
    this.form.reset();
    this.editMode = false;
  }

  deleteItem(){
    this.shoppingService.deleteIngredient(this.editedItemId);
    this.clearForm();
  }

  ngOnDestroy(){
    this.subscription.unsubscribe();
  }
}
