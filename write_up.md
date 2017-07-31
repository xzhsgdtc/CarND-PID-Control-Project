PID write up 
==============

---

## Describe the effect each of the P, I, D components had in your implementation.

* P stands for "proportional",  it's value is proportional to the cross-track error (CTE).  It's weight Kp determine how responsive the controler is. Larger the Kp, more responsive to the CTE and therefore easier to make sharp turns. But if it's too large, the the car would be very unstable and over shoot a lot. 



* I stands for "integral", it's proportional to the sum of CTE, and we use this to reduce system bias(if exist) to continuously decrease the error. If the system doesn't have much system error, the weight of this term Pi should be a very small number, since it's propotional to the sum of the error, too large will easily get everything out of track. 

* D stands for "differential", this term is proportional to the rate of change of the CET. It will prevent the P term to overshoot as a result damping the oscillation of vehicle create by the P term. However, itself also create oscillation, higher the D term will result a higher frequency oscillation. 



##### Thoughts:  Since D term is first order derivative, it compensate the overshoot by the P term, we could add second order derivative DD term to control the oscillation of the D term, and DDD term DDDD term ......   Also for the bias where we assumming a constant bias so that the first order of integral could reduce it. What if we have a system error is popotional to the CET, maybe we need to add a intergral of the intergral......    In summary, although I am new to control theory, I don't think PID is a good solution. In the end, it's an first oder linear approximation 
  
---



## Describe how to chose the final hyperparameters (P, I, D coefficients). 

I tuned the hyperparameters mannually. 

1. Find a good P turn that is large enough to make turns and stable enough to not too much oscillation. I tried 5,1,0.5,0.1 (Note that I can choose slightly a larger P, since we will have the D term to reduce the oscillation)
2. Find a corresponding D term I tried 1,5,10,20
3. Find a small I term since we don't have a large system error, so I set a small I term, and it works well. I use 0.0005

I found a lot of combination works, and then plot the CTE vs Average error. 

![propotional and differential](./data/P_1_D_20_result.html "P=1  D=20")


![propotional and differential](./data/P_04_I_00005_D_5_result.html "P=0.4  D=5")
