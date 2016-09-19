/**
 *  Клас AlgebraicOperations здійснює основні арифметичні операції із введеними числами: додавання, віднімання, множення, ділення
 */
class AlgebraicOperations
 {
  public:
   /**
    * Текстовий рядок, що містить арифметичний знак, операції, що буде здійснюватися
    */
   String operation_flag;
//------------------------OperationsFlags-----------------------------------//
   /**
    * Здійснює встановлення прапорця операцій на "+", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param i_m Об'єкт класу InputManager
    */
   void preAdd(InputManager &i_m)
    {
     if(i_m.validate(Form1->Edit1->Text))
     operation_flag = "+";
     i_m.clean();
     Form1->comma_btn->Enabled = true;
    }

    /**
    * Здійснює встановлення прапорця операцій на "-", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param i_m Об'єкт класу InputManager
    */
   void preMinus(InputManager &i_m)
    {
     if(i_m.validate(Form1->Edit1->Text))
     operation_flag = "-";
     i_m.clean();
     Form1->comma_btn->Enabled = true;
    }

   /**
    * Здійснює встановлення прапорця операцій на "*", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param i_m Об'єкт класу InputManager
    */
   void preMultiply(InputManager &i_m)
    {
     if(i_m.validate(Form1->Edit1->Text))
     operation_flag = "*";
     i_m.clean();
     Form1->comma_btn->Enabled = true;
    }

   /**
    * Здійснює встановлення прапорця операцій на "/", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param i_m Об'єкт класу InputManager
    */
   void preDivide(InputManager &i_m)
    {
     if(i_m.validate(Form1->Edit1->Text))
     operation_flag = "/";
     i_m.clean();
     Form1->comma_btn->Enabled = true;
    }
//---------------------------Operations--------------------------------------//
   /**
    * Здійснює зміну знаку поточного числа на протилежний, за умови що введене число пройшло валідацію
    * @param i_m Об'єкт класу InputManager
    */
   void signSwitcher(InputManager &i_m)
   {
    if(i_m.validate(Form1->Edit1->Text))
     Form1->Edit1->Text = FloatToStr(StrToFloat(Form1->Edit1->Text)*(-1));
     Form1->comma_btn->Enabled = true;
   }

   /**
    * Здійснює арифметичне додавання двох чисел, які зберігаються в об'єкті класу InputManager
    * @param  i_m Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися додавання
    * @return     Суму двох чисел дійсного типу, отриманих к параметри
    */
   double add(InputManager i_m)
   {
    return i_m.f_num + i_m.s_num;
   }

    /**
    * Здійснює арифметичне віднімання двох чисел, які зберігаються в об'єкті класу InputManager
    * @param  i_m Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися віднімання
    * @return     Різницю двох чисел дійсного типу, отриманих як параметри
    */
   double minus(InputManager i_m)
   {
    return i_m.f_num - i_m.s_num;
   }

    /**
    * Здійснює арифметичне множення двох чисел, які зберігаються в об'єкті класу InputManager
    * @param  i_m Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися множення
    * @return     Добуток двох чисел дійсного типу, отриманих як параметри
    */
   double multiply(InputManager i_m)
   {
    return i_m.f_num * i_m.s_num;
   }

    /**
    * Здійснює ділення двох чисел за умови, що дільник не дорівнює нулю. В іншому випадку виводить відповідне повідомлення.
    * @param  i_m Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися ділення
    * @return     Частку двох чисел дійсного типу, отриманих як параметри
    * @return     0, якщо дільник дорівнює нулю. Значення "0" свідчить про неможливість виконання такої операції
    */
   double divide(InputManager i_m)
   {
    if(i_m.s_num != 0)
     return i_m.f_num / i_m.s_num;
    else
     {
      ShowMessage("Can`t divide by ZERO");
      return 0;
     }
   }

   /**
    * Здійснює піднесення до квадрату числа, отриманого як параметр типу InputManager. У випадку недійсного вхідного значення виводить
    * відповідне повідомлення.
    * @param i_m Об'єкт класу InputManager
    */
   void Square(InputManager i_m)
   {
    if(i_m.validate(Form1->Edit1->Text))
    {
     Form1->Edit1->Text = FloatToStr(pow(StrToFloat(Form1->Edit1->Text),2));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
   }

   /**
    * Здійснює виведення модуля (абсолютного значення) числа. У випадку недійсного введення виводить відповідне повідомлення
    * @param i_m Об'єкт класу InputManager
    */
   void Modulus(InputManager i_m)
   {
    if(i_m.validate(Form1->Edit1->Text))
     {
      Form1->Edit1->Text = FloatToStr(fabs(StrToFloat(Form1->Edit1->Text)));
      Form1->comma_btn->Enabled = true;
     }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
   }

   /**
    * Здійснює обчислення та виведення квадратного кореня введеного числа. У випадку, якщо число від'ємне чи є недійсним,
    * виводить відповідне повідомлення.
    * @param i_m Об'єкт класу InputManager
    */
   void squareRoot(InputManager i_m)
   {
    if(i_m.validate(Form1->Edit1->Text) && StrToFloat(Form1->Edit1->Text) > 0)
    {
     Form1->Edit1->Text = FloatToStr(sqrt(StrToFloat(Form1->Edit1->Text)));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
   }

 };
