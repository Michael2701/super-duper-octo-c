import { Component, OnInit, OnDestroy } from '@angular/core';
import { Ingredient } from '../shared/ingredient.model';
import { ShoppingService } from './shopping.service';
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-shopping-list',
  templateUrl: './shopping-list.component.html',
  styleUrls: ['./shopping-list.component.scss']
})
export class ShoppingListComponent implements OnInit, OnDestroy {
  ingredients: Ingredient[] = [];
  ingredient: Ingredient;
  private subscr: Subscription;

  constructor(private shoppingService: ShoppingService) { 
    this.subscr = this.shoppingService.ingridientAdded.subscribe(
      (ingredients: Ingredient[]) => {
        this.ingredients = ingredients;
      }
    );
  }

  ngOnInit(): void {
    this.ingredients = this.shoppingService.getIngredients();
  }

  onEditItem(id: number){
    this.shoppingService.startingEditing.next(id);
  }

  ngOnDestroy(): void{
    this.subscr.unsubscribe();
  }

}

