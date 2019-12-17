# 4.8 Exercises

## 4.8.1 Sorting by Magnitude

Create a vector of double and initialize it with the values -9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4,
8.2. You can use an initializer list. Sort the values by magnitude. Write
- A functor and
- A lambda expression for the comparison.
Try both solutions.

## 4.8.2 STL Container

Create a std::map for phone numbers; i.e., map from a string to an unsigned long . Fill the
map with at least four entries. Search for an existing and a non-existing name. Also search
for an existing and a non-existing number.

## 4.8.3 Complex Numbers

Implement a visualization of the Julia set (of a quadratic polynomial) similar to the
Mandelbrot set. The mere difference is that the constant added to the square function
is independent of the pixel position. Essentially, you have to introduce a constant k and
modify iterate a little.

- Start with k = −0.6 + 0.6i which is a complex Cantor dust, also known
as Fatou dust.
- Try other values for k, like 0.353 + 0.288i (compare http://warp.povusers.org/
Mandelbrot). Eventually you may want to change the color scheme to come up with a
cooler visualization.
- The challenge in software design is to write an implementation for both Mandelbrot
and Julia sets with minimal code redundancy. (The algorithmic challenge is probably
finding colors that look good for all k. But this goes beyond the scope of this book.)
- Advanced: Both fractals can be combined in an interactive manner. For this, one has
to provide two windows. The first one draws the Mandelbrot set as before. In addition,
it can enable mouse input so that the complex value under the mouse cursor is used as
k for the Julia set in the second window.
- Pretty advanced: If the calculation of the Julia set is too slow, one can use thread
parallelism or even GPU acceleration with CUDA or OpenGL.
