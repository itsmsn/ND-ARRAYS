# ND-ARRAYS C++
a template class ndArray to provide such facility. Note that the array should hold elements of any type in one linear array, in row major order, and should be able to provide any number of dimensions for user.
</br>
Your ndArray- ADT should provide following functions:</br>
1. Insert: Add an element at a given index.</br>
2. Delete: Search and removes an element from array at a given index.</br>
3. Extend: Double the array in size.</br>
4. Shrink: Reduce the array size to half.</br>
5. Subscript operator: You will overload operator for (1 to 4) dimensions.</br>
6. Retrieve: Search and return any element from array.</br>
7. Print: by overloading stream insertion operator (<<): Prints all elements of array
according to dimensions. (Up till 3rd dimensions print in table form, for higher
dimensions just print linear data)</br>
8. Constructor: Take dimensions of multi-D array.</br>
9. Destructor</br>
10. Copy Constructor</br>
Hint: You can add an extra array to store dimensions.</br>
