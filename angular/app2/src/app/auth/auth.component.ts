import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, Validators } from '@angular/forms';
import { AuthService, AuthResponseData } from './auth.service';
import { Observable } from 'rxjs';
import { Router } from '@angular/router';

@Component({
  selector: 'app-auth',
  templateUrl: './auth.component.html',
  styleUrls: ['./auth.component.scss']
})
export class AuthComponent implements OnInit {
  loginForm: FormGroup;
  formIsNotValid = true;
  formMode = true;
  isLoading = false;
  errorMessage = null;

  constructor(
    private authService: AuthService,
    private router: Router
  ) { }

  ngOnInit(): void {
    this.loginForm = new FormGroup({
      'email': new FormControl(null, [Validators.required, Validators.email]),
      'password': new FormControl(null, [Validators.required, Validators.minLength(6)])
    });
    this.loginForm.statusChanges.subscribe(
      value => {
        this.formIsNotValid = value == 'VALID' ?  false : true;
      }
    )
  }

  swithchMode(){
    this.formMode = !this.formMode;
  }

  onSubmit(){
    if(this.loginForm.invalid) return;
    this.isLoading = true;
    this.errorMessage = null;

    let authObs: Observable<AuthResponseData>

    const email = this.loginForm.value['email'];
    const password = this.loginForm.value['password'];

    if(this.formMode){
      authObs = this.authService.signup(email, password);
    }else{
      authObs = this.authService.login(email, password);
    }

    authObs.subscribe(
      response => {
        console.log(response);
        this.isLoading = false;
        this.router.navigate(['/recipes']);
      },
      errorMessage => {
        console.log(errorMessage);
        this.isLoading = false;
        this.errorMessage = errorMessage;
    });
    this.loginForm.reset();
  }
}
