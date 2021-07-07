# Thermal Conduction
Calculates and represents thermal conduction in 2 dimensions via elliptic partial differential equations.

# Formulas  
Calculation at each grid point:   
![partial](https://i.imgur.com/Ntl0cHM.png)    
Calculation of the residual:    
![residual](https://i.imgur.com/o4wwVxR.png)    
    
# Parameters    
DXNUM = number of columns to simulate
DYNUM = number of rows to simulate  
ERR &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;= convergence error   
    
# Resulting Graph   
This was achieved with the following parameters and plotted on excel:   
DXNUM = 21    
DYNUM = 21    
ERR &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; = 1.0e-8  
    
![Graph](https://i.imgur.com/N2TrcE1.png)
