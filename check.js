import fs from "fs";
import { argv } from "process";

main();

async function main() {
    const inputs = argv.slice(2);
    let status = await check_database(inputs.length === 1 ? inputs[0] : null);
    console.log(`Solutions: `, status);
    return 0;
}

async function check_database(prob = null) {
    const folder = "./solutions/";
    let filenames = fs.readdirSync(folder);
    if (prob) {
        let checker = filenames.filter((filename) => filename.includes(String(prob)));
        return !!checker.length;
    } else {
        let count = 0;
        for (let i = 1001; i <= 3000; i++) {
            let checker = filenames.filter((filename) => filename.includes(String(i)));
            if (checker.length) count++;
        }
        return count;
    }
}
