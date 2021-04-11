
#include<math.h>

#ifndef TOOLS_H
#define TOOLS_H

/*NOTE:
 * https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
 * */

float round2(float var)         /* redondear a 2 decimales */
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

float prc_error(float e, float t)
{
    /* e valor experimental, t es el valor teorico */
    return (fabs(e - t) / fabs(t)) * 100;
}

#endif
