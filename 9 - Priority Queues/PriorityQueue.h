//
//  PriorityQueue.hpp
//  9 - Priority Queues
//
//  Created by Andre Carrera on 11/15/16.
//  Copyright © 2016 Carrera. All rights reserved.
//

#pragma once
#include <exception>

using namespace std;

template <typename type>
class PriorityQueue {
    int leftChildIdx(int nodeIdx)
    {
        return 2 * nodeIdx + 1;
    }
    int rightChildIdx(int nodeIdx)
    {
        return 2 * nodeIdx + 2;
    }
    int parentIdx(int nodeIdx)
    {
        return (nodeIdx -1)/2;
    }
    void swap(int leftIdx, int rightIdx)
    {
        type tempdata = _data[leftIdx];
        _data[leftIdx]=_data[rightIdx];
        _data[rightIdx]= tempdata;

    }
    size_t _count;
    const int  MAXSIZE = 16;
    
    type * _data;
    
public:
    PriorityQueue()
    {
        _data= new type[MAXSIZE];
        _count= 0;
    }
    
    void Enqueue(type x)
    {
        if (_count>= MAXSIZE) {
            throw std::out_of_range ("Index out of bounds.");

        }
        
        int currIndex = _count;
        _data[currIndex] = x;
        
        int parIndex = parentIdx(currIndex);
        while (_data[currIndex]>_data[parIndex]) {
            swap(currIndex, parIndex);
            
            currIndex = parIndex;
            
            parIndex = parentIdx(currIndex);
        }

        _count ++;
        
    }
    type Dequeue()
    {
        int min = 1;
        if (_count< min ) {
            throw std::out_of_range ("Index out of bounds.");
        }
        type item = _data[0];
        
        
        _data[0] = _data[_count -1 ];
        _count --;
        int currIdx = 0;
        
        while (true) {
            int leftIdx = leftChildIdx(currIdx);
            int rightIdx = leftIdx +1;
            
            if (leftIdx >= _count) {
                break;
            }
            
            if (_data[currIdx]>= _data[leftIdx] &&
                _data[currIdx]>= _data[rightIdx]) {
                break;
            }
            
            if (_data[leftIdx]> _data[rightIdx]) {
                swap(currIdx, leftIdx);
                currIdx = leftIdx;
            }
            else {
                swap(currIdx, rightIdx);
                currIdx = rightIdx;
            }
        }
        
        return item;
        
    }
    size_t Count()
    {
        return _count;
    }
    void Clear()
    {
        _count = 0;
    }

};
