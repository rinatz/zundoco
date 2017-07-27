function choice(array) {
    const index = Math.floor(Math.random() * array.length);
    return array[index];
}

function sleep(seconds) {
    const msec = seconds * 1000;
    const start = new Date().getTime();

    while (new Date().getTime() - start < msec) {
        continue;
    }

    return;
}

function zundoco() {
    const choices = ['ズン', 'ドコ'];
    const expected = ['ズン', 'ズン', 'ズン', 'ズン', 'ドコ'];
    const finish = ['キ・', 'キ・ヨ・', 'キ・ヨ・シ！'];

    let words = [];

    for (let i = 0; i < 5; i++) {
        words.push(choice(choices));
    }

    while (true) {
        if (words.toString() == expected.toString()) {
            let seconds = 1.2;

            for (let word of words) {
                process.stdout.write(word + '\n');
                sleep(seconds);
                seconds = 0.6;
            }

            for (let word of finish) {
                process.stdout.write('\r' + word);
                sleep(0.3);
            }

            process.stdout.write('\n');

            return;
        }

        console.log(words.shift());

        words.push(choice(choices));
    }
}

function main() {
    zundoco();
}

main();
