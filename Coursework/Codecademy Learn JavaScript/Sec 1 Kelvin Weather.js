// Today's forecast
const kelvin = 293;
// Kelvin converted to degrees Celsius
const celsius = kelvin - 273;
// Celsius converted to degrees Fahrenheit
let fahrenheit = celsius * (9/5) + 32;
// Rounding down decimal result to an integer value
fahrenheit = Math.floor(fahrenheit);
//
console.log(`The temperature is ${fahrenheit} degrees Fahrenheit.`);

// Bonus Question
// Convert celsius to the Newton scale, round down, and log the result
let newton = celsius * (33/100);
newton = Math.floor(newton);
console.log(`The temperature is ${newton} degrees Newton.`);