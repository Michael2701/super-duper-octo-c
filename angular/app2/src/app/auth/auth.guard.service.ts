import { CanActivate, ActivatedRouteSnapshot, RouterStateSnapshot, Router, UrlTree } from '@angular/router';
import { Observable } from 'rxjs';
import { Injectable } from '@angular/core';
import { AuthService } from './auth.service';
import { map, take } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})

export class AuthGuard  implements CanActivate{
  constructor(
    private authService: AuthService,
    private router: Router
  ){}

  canActivate(
    route: ActivatedRouteSnapshot,
    state: RouterStateSnapshot ): 
    boolean | UrlTree | Promise<boolean | UrlTree> | Observable<boolean | UrlTree> 
  {
    return this.authService.user.pipe(
      take(1),
      map( user => {
        const isAuth = !!user;
        return isAuth ? isAuth  : this.router.createUrlTree(['/auth']);
    }));

  }
}