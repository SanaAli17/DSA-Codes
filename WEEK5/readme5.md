# Priority Queue ADT  

## Overview  
This project implements a *Priority Queue (PQ) Abstract Data Type (ADT)* using *object composition* in C++. A priority queue is a collection of items where each item has a priority level, and elements with higher priority are dequeued first.  

## Features  
- Initialize an empty priority queue  
- Check if the priority queue is *empty* or *full*  
- *Insert* an item based on its priority level  
- *Remove* the highest-priority item  
- Support for *10 priority levels* (can be modified to handle *N* priority levels)  

## Implementation  
The priority queue is implemented using an *array of queues*, where each queue corresponds to a priority level.