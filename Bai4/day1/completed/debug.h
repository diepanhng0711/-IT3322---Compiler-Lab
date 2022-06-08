/* 
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#ifndef __DEBUG_H__
#define __DEBUG_H_

#include "symtab.h"

void printType(Type* type);                                     //In thông tin kiểu
void printConstantValue(ConstantValue* value);                  //In giá trị hằng số
void printObject(Object* obj, int indent);                      //In thông tin đối tượng
void printObjectList(ObjectNode* objList, int indent);          //In thông tin danh sách đối tượng
void printScope(Scope* scope, int indent);                      //In block (nằm trong scope đó)

#endif
