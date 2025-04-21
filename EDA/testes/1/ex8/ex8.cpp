#include <iostream>
using namespace std;

struct Rectangle{
	int width;
	int height;
};

int scale_rectangle_ptr(Rectangle *rectangle, int factor)
{
  if(rectangle == nullptr){
    return -1;
  }
  rectangle->height = rectangle->height * factor;
  rectangle->width = rectangle->width *factor;

  return 0;
} 


int scale_rectangle_ref(Rectangle &rectangle, int *factor)
{
  if(factor == nullptr){
    return -1;
  }
  int fator = *factor;
  rectangle.height = rectangle.height * fator;
  rectangle.width = rectangle.width * fator;

  return 0;
}

Rectangle *copy_scaled_rectangle(Rectangle *rectangle, int factor)
{
  Rectangle *nRec = new Rectangle;
  if(rectangle == nullptr){
    return nullptr;
  } 

  nRec->height = rectangle->height * factor;
  nRec->width = rectangle->width * factor;
  
  return nRec;
}

int swap_dims_rectangles(Rectangle *rectangle1, Rectangle &rectangle2)
{
  if(rectangle1 == nullptr){
    return -1;
  }
  Rectangle auxR;
  auxR = *rectangle1;
  *rectangle1 = rectangle2;
  rectangle2 = auxR;

  return 0;
}



/* ---------- Test Code. Do not change ---------- */ 
int main()
{
    Rectangle rect1{7,8};
    Rectangle rect2{23,12};
    Rectangle rect3{-2, 7};
    Rectangle rect4{9, 0};
    Rectangle rect5{3, -1};
    int result;
    int factor;
    
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    cout <<  "---------- Testing the scale_rectangle_ptr function ---------- " << endl << endl; 
    cout <<  "In main() rectangle 1 dimensions are: " << rect1.height << " height, " << rect1.width << " width."<< endl;
    result = scale_rectangle_ptr(&rect1, 4);
    cout << "Rectangle 1 dimensions in main after calling scale_rectangle_ptr are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    cout << "The result value in main after calling scale_rectangle_ptr is " << result << endl << endl;
    
    result = scale_rectangle_ptr(&rect1, 0);
    cout << "Rectangle 1 dimensions in main after calling scale_rectangle_ptr are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    cout << "The result value in main after calling scale_rectangle_ptr is " << result << endl << endl;
    
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    cout <<  "---------- Testing the scale_rectangle_ref function ---------- " << endl << endl; 
    cout <<  "In main() rectangle 1 dimensions are: " << rect1.height << " height, " << rect1.width << " width."<< endl;
    factor = 4;
    result = scale_rectangle_ref(rect1, &factor);
    cout << "Rectangle 1 dimensions in main after calling scale_rectangle_ref are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    cout << "The result value in main after calling scale_rectangle_ref is " << result << endl << endl;

    result = scale_rectangle_ref(rect1, nullptr);
    cout << "Rectangle 1 dimensions in main after calling scale_rectangle_ref are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    cout << "The result value in main after calling scale_rectangle_ref is " << result << endl << endl;
       
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    cout <<  "---------- Testing the copy_scaled_rectangle function ---------- " << endl << endl; 
    cout <<  "In main() rectangle 1 dimensions are: " << rect1.height << " height, " << rect1.width << " width."<< endl;
    Rectangle* copy_rectangle;
    copy_rectangle = copy_scaled_rectangle(&rect1, 4);
    cout << "Rectangle 1 dimensions in main after calling copy_scaled_rectangle are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    if (copy_rectangle != nullptr)
    {
        cout << "Copy of rectangle dimensions in main after calling copy_scaled_rectangle function are " << copy_rectangle->height << " height, " << copy_rectangle->width << " width."<< endl<<endl;
    }
    else
    {
        cout << "copy_scaled_rectangle function returned an error! "<< endl << endl;
    }

    copy_rectangle = copy_scaled_rectangle(&rect1, 0);
    cout << "Rectangle 1 dimensions in main after calling copy_scaled_rectangle are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    if (copy_rectangle != nullptr)
    {
        cout << "Copy of rectangle dimensions in main after calling copy_scaled_rectangle function are " << copy_rectangle->height << " height, " << copy_rectangle->width << " width."<< endl<<endl;
    }
    else
    {
        cout << "copy_scaled_rectangle function returned an error! "<< endl << endl;
    }
    
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------*/
    cout <<  "---------- Testing the swap_dims_rectangles function ---------- " << endl << endl; 
    cout <<  "In main() rectangle 1 dimensions are: " << rect1.height << " height, " << rect1.width << " width."<< endl;
    cout <<  "In main() rectangle 2 dimensions are: " << rect2.height << " height, " << rect2.width << " width."<< endl;
    result = swap_dims_rectangles(&rect1, rect2);
    cout << "Rectangle 1 dimensions in main after swap_dims_rectangles are " << rect1.height << " height, " << rect1.width << " width."<< endl;
    cout << "Rectangle 2 dimensions in main after swap_dims_rectangles are " << rect2.height << " height, " << rect2.width << " width."<< endl;
    cout << "The result value in main after calling swap_dims_rectangles is " << result << endl << endl;

    cout <<  "In main() rectangle 2 dimensions are: " << rect2.height << " height, " << rect2.width << " width."<< endl;
    cout <<  "In main() rectangle 4 dimensions are: " << rect4.height << " height, " << rect4.width << " width."<< endl;
    result = swap_dims_rectangles(&rect4, rect2);
    cout << "Rectangle 2 dimensions in main after swap_dims_rectangles are " << rect2.height << " height, " << rect2.width << " width."<< endl;
    cout << "Rectangle 4 dimensions in main after swap_dims_rectangles are " << rect4.height << " height, " << rect4.width << " width."<< endl;
    cout << "The result value in main after calling swap_dims_rectangles is " << result << endl << endl;

    return 0;
}
