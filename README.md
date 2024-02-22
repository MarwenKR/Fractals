## Fractals 

Implemented the Julia set fractals. you ccould change the constant and the power for more diverse shape generation.

 
$$ z_{n+1}= z_{n}^p + c$$

- $p$ is the power number defining the set.
- $c$ is a random fixed complex number ($c$ should be differetn than $2$ ans $0$).

---

To run the program:

```
./config.sh
./build.sh
./run.sh
```
>
---
### Outputs
 <p align="center">
 <img center src="images/test_0.png" width=300 height=250/><img center src="images/test_1.png" width=300 height=250/> 
 </p>
  <p align="center">
 <img center src="images/test_2.png" width=300 height=250/><img center src="images/test_4.png" width=300 height=250/> 
 </p>
---
### Resources:

* [Julia set (wiki)](https://en.wikipedia.org/wiki/Julia_set)
* [glfw](https://www.glfw.org/) 