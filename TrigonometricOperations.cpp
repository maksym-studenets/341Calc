/**
 * Клас TrigonometricOperations призначений для виконання основних тригонометричних операцій над числами
 */
class TrigonometricOperations
{
 public:
 /**
  * Здійснює обчислення та виведення синуса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param manager Об'єкт класу InputManager, в якому зберігається аргумент
  */
 void Sine(InputManager manager)
 {
  if(manager.validate(Form1->Edit1->Text))
    {
     float argument = FloatToStr(StrToFloat(Form1->Edit1->Text));
     float sine = sin(argument * (M_PI / 180));

     Form1->Edit1->Text = FloatToStr(sine);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Неправильні вхідні дані");
     manager.clean();
    }
 }

/**
  * Здійснює обчислення та виведення косинуса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param manager Об'єкт класу InputManager, в якому зберігається аргумент
  */
  void Cosine(InputManager manager)
 {
  if(manager.validate(Form1->Edit1->Text))
    {
      float argument = FloatToStr(StrToFloat(Form1->Edit1->Text));
      float cosine = cos(argument * (M_PI / 180));

      Form1->Edit1->Text = FloatToStr(cosine);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Неправильні вхідні дані");
     manager.clean();
    }
 }

   /**
  * Здійснює обчислення та виведення тангенса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param manager Об'єкт класу InputManager, в якому зберігається аргумент
  */
  void Tangent(InputManager manager)
 {
  if(manager.validate(Form1->Edit1->Text))
    {
      float argument = FloatToStr(StrToFloat(Form1->Edit1->Text));
     float tangent = tan(argument * (M_PI / 180));

     Form1->Edit1->Text = FloatToStr(tangent);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Неправильні вхідні дані");
     manager.clean();
    }
 }

/**
  * Здійснює обчислення та виведення котангенса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param manager Об'єкт класу InputManager, в якому зберігається аргумент
  */ 
  void Cotangent(InputManager manager)
 {
  if(manager.validate(Form1->Edit1->Text) && tangent != 0)
    {
      float argument = FloatToStr(StrToFloat(Form1->Edit1->Text));
      float cotangent = 1 / tangent(argument * (M_PI / 100));

     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Неправильні вхідні дані");
     manager.clean();
    }
  }

 
 /**
  * Здійснює переведення та виведення значення дійсного числа у градусах в радіани. 
  * У випадку неможливості виконання операції виводить відповідне повідомлення
  * @param manager Об'єкт класу InputManager, в якому зберігається аргумент
  */
  void Radian(InputManager manager)
 {
  if(manager.validate(Form1->Edit1->Text))
    {
     float argument = StrToFloat(Form1->Edit1->Text);
     float radians = argument * (M_PI / 180);

     Form1->Edit1->Text = FloatToStr(radians);
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Неправильні вхідні дані");
     manager.clean();
    }
 }

  ////////////  HYPERBOLIC TRIGONOMETRIC FUNCTIONS ////////////////

  /**
   * Обчислює та виводить значення гіперболічного синуса аргумента. У випадку неможливості виконання операції виводить відповідне повідомлення
   * @param manager Об'єкт класу InputManager
   * @author Maksym
   * @since 1.1
   */
  void hyperbolicSine(InputManager manager) 
  {
    if (manager.validate(Form1->Edit1->Text))
    {
        float argument = StrToFloat(Form1->Edit1->Text);
        float sinh = sinh(argument);

        Form1->Edit1->Text = FloatToStr(sinh);
        Form1->comma_btn->Enabled = true;
    }
    else
    {
         ShowMessage("Неправильні вхідні дані");
         manager.clean();
    }
  }

    /**
   * Обчислює та виводить значення гіперболічного косинуса аргумента. У випадку неможливості виконання операції виводить відповідне повідомлення
   * @param manager Об'єкт класу InputManager
   * @author Maksym
   * @since 1.1
   */
    void hyperbolicCosine(InputManager manager) 
  {
    if (manager.validate(Form1->Edit1->Text))
    {
        float argument = StrToFloat(Form1->Edit1->Text);
        float cosh = cos(argument);

        Form1->Edit1->Text = FloatToStr(cosh);
        Form1->comma_btn->Enabled = true;
    }
    else
    {
         ShowMessage("Неправильні вхідні дані");
         manager.clean();
    }
  }

    /**
   * Обчислює та виводить значення гіперболічного тангенса аргумента. У випадку неможливості виконання операції виводить відповідне повідомлення
   * @param manager Об'єкт класу InputManager
   * @author Maksym
   * @since 1.1
   */
    void hyperbolicTangent(InputManager manager) 
  {
    if (manager.validate(Form1->Edit1->Text))
    {
        float argument = StrToFloat(Form1->Edit1->Text);
        float tgh = tanh(argument);

        Form1->Edit1->Text = FloatToStr(tgh);
        Form1->comma_btn->Enabled = true;
    }
    else
    {
         ShowMessage("Неправильні вхідні дані");
         manager.clean();
    }
  }

    /**
   * Обчислює та виводить значення гіперболічного котангенса аргумента. У випадку неможливості виконання операції виводить відповідне повідомлення
   * @param manager Об'єкт класу InputManager
   * @author Maksym
   * @since 1.1
   */
    void hyperbolicCotangent(InputManager manager) 
  {
    if (manager.validate(Form1->Edit1->Text) && tanh != 0)
    {
        float argument = StrToFloat(Form1->Edit1->Text);
        float cth = 1 / tanh(argument);

        Form1->Edit1->Text = FloatToStr(cth);
        Form1->comma_btn->Enabled = true;
    }
    else
    {
         ShowMessage("Неправильні вхідні дані");
         manager.clean();
    }
  }
};
