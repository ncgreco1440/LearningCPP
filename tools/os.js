const os = require('os');
const MY_OS = os.type();

if (MY_OS == 'Windows_NT') {
    console.log('Windows');
} else {
    console.log(MY_OS);
}