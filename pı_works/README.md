**_This project was implemented on by Rahim ÇUBUK and Çağrı ESEN.._**

Write code for below problem. The input below is just an example and you should implement independent from the
input. Please paste the link to the answer shared using pastebin, dotnetfiddle, jsfiddle, or any other similar
web-site.
## _Question :_
- You will have a ORTHOGONAL TRIANGLE input from a file and you need to find the maximum sum of the numbers according
to given rules below;

1. You will start from the top and move downwards to an adjacent number as in below.
2. You are only allowed to walk downwards and diagonally.
3. You can only walk over NON PRIME NUMBERS.
4. You have to reach at the end of the pyramid as much as possible.

- According to above rules the maximum sum of the numbers from top to bottom in below example is 24.
```
    *1 
   *8 4 
  2 *6 9
 8 5 *9 3  
```   
- As you can see this has several paths that fits the rule of NOT PRIME NUMBERS; 1>8>6>9, 1>4>6>9, 1>4>9>9
  
  1 + 8 + 6 + 9 = 24.  

- As you see 1, 8, 6, 9 are all NOT PRIME NUMBERS and walking over these yields the maximum sum.

## _Solution :_

![3](https://user-images.githubusercontent.com/32637622/60755568-374dd980-9ffa-11e9-850e-14f40c560826.PNG)
