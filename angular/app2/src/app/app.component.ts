import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'app2';
  feature = 'recipe';

  onNavigate(feature: string){
    console.log(feature);
    this.feature = feature;
  }
}
