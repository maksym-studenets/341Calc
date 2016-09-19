/**
 * Клас TrigonometricOperations призначений для виконання основних тригонометричних операцій над числами
 */
class TrigonometricOperations
{
 public:
 /**
  * Здійснює обчислення та виведення синуса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param i_m Об'єкт класу InputManager, в якому зберігається аргумент
  */
 void Sine(InputManager i_m)
 {
  if(i_m.validate(Form1->Edit1->Text))
    {
     Form1->Edit1->Text = FloatToStr(sin(StrToFloat(Form1->Edit1->Text)*(M_PI/180)));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
 }

/**
  * Здійснює обчислення та виведення косинуса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param i_m Об'єкт класу InputManager, в якому зберігається аргумент
  */
  void Cosine(InputManager i_m)
 {
  if(i_m.validate(Form1->Edit1->Text))
    {
     Form1->Edit1->Text = FloatToStr(cos(StrToFloat(Form1->Edit1->Text)*(M_PI/180)));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
 }

   /**
  * Здійснює обчислення та виведення тангенса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param i_m Об'єкт класу InputManager, в якому зберігається аргумент
  */
  void Tangent(InputManager i_m)
 {
  if(i_m.validate(Form1->Edit1->Text))
    {
     Form1->Edit1->Text = FloatToStr(tan(StrToFloat(Form1->Edit1->Text)*(M_PI/180)));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
 }

/**
  * Здійснює обчислення та виведення котангенса дійсного числа. Вивиодить повідомлення, якщо операцію виконати неможливо
  * @param i_m Об'єкт класу InputManager, в якому зберігається аргумент
  */ 
  void Cotangent(InputManager i_m)
 {
  if(i_m.validate(Form1->Edit1->Text))
    {
     Form1->Edit1->Text = FloatToStr(1/tan(StrToFloat(Form1->Edit1->Text)*(M_PI/180)));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
  }

 
 /**
  * Здійснює переведення та виведення значення дійсного числа у градусах в радіани. 
  * У випадку неможливості виконання операції виводить відповідне повідомлення
  * @param i_m Об'єкт класу InputManager, в якому зберігається аргумент
  */
  void Radian(InputManager i_m)
 {
  if(i_m.validate(Form1->Edit1->Text))
    {
     Form1->Edit1->Text = FloatToStr(StrToFloat(Form1->Edit1->Text)*(M_PI/180));
     Form1->comma_btn->Enabled = true;
    }
    else
    {
     ShowMessage("Wrong input data");
     i_m.clean();
    }
 }
};
