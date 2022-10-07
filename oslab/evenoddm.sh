echo  "Enter a number: " 
read number
if [ $((number%2))  ]
then
  echo "Number is even."
else
  echo "Number is odd."
fi
