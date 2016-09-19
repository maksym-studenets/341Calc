/**
 *  Клас AlgebraicOperations здійснює основні арифметичні операції із введеними числами: додавання, віднімання, множення, ділення
 */
class AlgebraicOperations
 {
  private:
   /**
    * Текстовий рядок, що містить арифметичний знак, операції, що буде здійснюватися
    */
   String operation_flag;
//------------------------OperationsFlags-----------------------------------//
public:
   /**
    * Здійснює встановлення прапорця операцій на "+", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param manager Об'єкт класу InputManager
    */
   void preAdd(InputManager &manager)
    {
     if (manager.validate(Form1->Edit1->Text))
     operation_flag = "+";
     manager.clean();
     Form1->comma_btn->Enabled = true;
    }

    /**
    * Здійснює встановлення прапорця операцій на "-", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param manager Об'єкт класу InputManager
    */
   void preMinus(InputManager &manager)
    {
     if (manager.validate(Form1->Edit1->Text))
     operation_flag = "-";
     manager.clean();
     Form1->comma_btn->Enabled = true;
    }

   /**
    * Здійснює встановлення прапорця операцій на "*", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param manager Об'єкт класу InputManager
    */
   void preMultiply(InputManager &manager)
    {
      if (manager.validate(Form1->Edit1->Text))
      operation_flag = "*";
      manager.clean();
      Form1->comma_btn->Enabled = true;
    }

   /**
    * Здійснює встановлення прапорця операцій на "/", якщо введене число пройшло валідацію.
    * Очищує поле для введення числа, а також робить активною кнопку для введення коми
    * @param manager Об'єкт класу InputManager
    */
   void preDivide(InputManager &manager)
    {
     if (manager.validate(Form1->Edit1->Text))
     operation_flag = "/";
     manager.clean();
     Form1->comma_btn->Enabled = true;
    }
//---------------------------Operations--------------------------------------//
   /**
    * Здійснює зміну знаку поточного числа на протилежний, за умови що введене число пройшло валідацію
    * @param manager Об'єкт класу InputManager
    */
   void signSwitcher(InputManager &manager)
   {
    if(manager.validate(Form1->Edit1->Text)) {
      float negative = StrToFloat( (Form1->Edit1->Text) * (-1) );
      Form1->Edit1->Text = FloatToStr(negative);
    }
     
     Form1->comma_btn->Enabled = true;
   }

   /**
    * Здійснює арифметичне додавання двох чисел, які зберігаються в об'єкті класу InputManager
    * @param  manager Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися додавання
    * @return     Суму двох чисел дійсного типу, отриманих к параметри
    */
   double add(InputManager manager)
   {
    return manager.getFirstNum() + manager.getSecondNum();
   }

    /**
    * Здійснює арифметичне віднімання двох чисел, які зберігаються в об'єкті класу InputManager
    * @param  manager Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися віднімання
    * @return     Різницю двох чисел дійсного типу, отриманих як параметри
    */
   double minus(InputManager manager)
   {
    return manager.getFirstNum() - manager.getSecondNum();
   }

    /**
    * Здійснює арифметичне множення двох чисел, які зберігаються в об'єкті класу InputManager
    * @param  manager Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися множення
    * @return     Добуток двох чисел дійсного типу, отриманих як параметри
    */
   double multiply(InputManager manager)
   {
    return manager.getFirstNum() * manager.getSecondNum();
   }

    /**
    * Здійснює ділення двох чисел за умови, що дільник не дорівнює нулю. В іншому випадку виводить відповідне повідомлення.
    * @param  manager Об'єкт класу InputManager, що містить два операнди, над якими буде проводитися ділення
    * @return     Частку двох чисел дійсного типу, отриманих як параметри
    * @return     0, якщо дільник дорівнює нулю. Значення "0" свідчить про неможливість виконання такої операції
    */
   double divide(InputManager manager)
   {
    if(manager.s_num != 0)
     return manager.getFirstNum() / manager.getSecondNum();
    else
     {
      ShowMessage("Can`t divide by ZERO");
      return 0;
     }
   }

   /**
    * Здійснює піднесення до квадрату числа, отриманого як параметр типу InputManager. У випадку недійсного вхідного значення виводить
    * відповідне повідомлення.
    * @param manager Об'єкт класу InputManager
    */
   void Square(InputManager manager)
   {
    if(manager.validate(Form1->Edit1->Text))
    {
     float base = StrToFloat( Form1->Edit1->Text );
     float power = pow(base, 2);
     Form1->Edit1->Text = FloatToStr(power);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     manager.clean();
    }
   }

   /**
    * Здійснює виведення модуля (абсолютного значення) числа. У випадку недійсного введення виводить відповідне повідомлення
    * @param manager Об'єкт класу InputManager
    */
   void Modulus(InputManager manager)
   {
    if(manager.validate(Form1->Edit1->Text))
     {
      float number = StrToFloat(Form1->Edit1->Text);
      float abs = fabs(number);

      Form1->Edit1->Text = FloatToStr(abs);
      Form1->comma_btn->Enabled = true;
     }
    else
    {
     ShowMessage("Wrong input data");
     manager.clean();
    }
   }

   /**
    * Здійснює обчислення та виведення квадратного кореня введеного числа. У випадку, якщо число від'ємне чи є недійсним,
    * виводить відповідне повідомлення.
    * @param manager Об'єкт класу InputManager
    */
   void squareRoot(InputManager manager)
   {
    if(manager.validate(Form1->Edit1->Text) && StrToFloat(Form1->Edit1->Text) >= 0)
    {
     float base = StrToFloat(Form1->Edit1->Text);
     float root = sqrt(base);

     Form1->Edit1->Text = FloatToStr(root);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     manager.clean();
    }
   }

   /**
   * Обчислює та виводить значення натурального логарифму аргумента. У випадку неможливості виконання операції виводить відповідне повідомлення
   * @param manager Об'єкт класу InputManager
   * @author Maksym
   * @since 1.1
   */
   void naturalLogarithm(InputManager manager) 
   {
    if(manager.validate(Form1->Edit1->Text) && StrToFloat(Form1->Edit1->Text) >= 0)
    {
     float argument = StrToFloat(Form1->Edit1->Text);
     float logarithm = log(argument);

     Form1->Edit1->Text = FloatToStr(logarithm);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     manager.clean();
    }
   }

 };
