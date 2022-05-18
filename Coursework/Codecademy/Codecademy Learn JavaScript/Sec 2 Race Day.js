let raceNumber = Math.floor(Math.random() * 1000);

let runnerEarlyRegistration = false;
let runnerAge = 5;

if (runnerAge > 18 && runnerEarlyRegistration === true) {
  raceNumber += 1000;
}

if (runnerAge > 18 && runnerEarlyRegistration === true) {
  console.log(`Your race begins at 9:30am. Your race number is: ${raceNumber}`);
}

else if (runnerAge > 18 && runnerEarlyRegistration === false) {
  console.log(`Your race begins at 11:00am. Your race number is: ${raceNumber}`);
}

else if (runnerAge < 18) {
  console.log(`Youth registrants run at 12:30pm. Your race number is: ${raceNumber}`);
}

else {
  console.log('Please refer to the registration desk.')
}