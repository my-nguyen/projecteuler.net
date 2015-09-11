struct slice_t
{
  int _data[4];

  void tostring(char* string);
}

void slice_t::tostring(char* string)
{
  strcpy(string, "");
  int i;
  for (i = 0; i < MAX_SLICE; i++)
  {
    sprintf(tmp, " %d", numbers[i]);
    strcat(string, tmp);
  }
  return string;
}

void main()
{
  slice_t slice;
  string char[20];
  slice.tostring(string);
}
