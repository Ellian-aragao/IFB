void setup()
{
}
void loop()
{
    int time = analogRead(0) - 1023;

    for (int i = 0; i < 255; i++)
    {
        time = analogRead(0) - 1023;
        analogWrite(3, i);
        delay(time);
    }
    for (int i = 255; i > 0; i--)
    {
        time = analogRead(0) - 1023;

        analogWrite(3, i);
        delay(time);
    }
}