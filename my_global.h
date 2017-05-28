#ifndef MY_GLOBAL_H
#define MY_GLOBAL_H

#define pi (acos(-1.0))
#define ang60 (-pi / 3.0)

#define eps 1e-9
#define e(x, y) (fabs((x) - (y)) <= eps)
#define l(x, y) (((x) + eps) < (y))
#define g(x, y) (l(y, x))

#define inf 1e9

#define showVar(x) #x << ": " << x

#define degreeToRadian(x) ((double(x)) * pi / 180.0)

#endif // MY_GLOBAL_H
