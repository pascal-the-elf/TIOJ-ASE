import puppeteer from "puppeteer";
import fs from "fs";
import { argv } from "process";

const SHOT = false;
const SHOW_CODE = true;

main();

async function main() {
    const inputs = argv.slice(2);
    let start = 1001,
        end = 1001;
    if (inputs.length == 2) {
        start = inputs[0];
        end = inputs[1];
    }
    console.log(`Ok, I will try to solve prob. ${start} to prob. ${end}`);

    const browser = await puppeteer.launch({ headless: false });
    console.log(`Browser Lauched.`);
    const page = await browser.newPage();
    console.log(`Page Opened.`);

    let user = cur_user() || gen_user();
    console.log("User Data: \n", user); /*
    await signup(page, user);
    await sleep(3000);*/
    await signin(page, user);
    console.log(`Signed In.`);
    await sleep(3000);
    if (SHOT) await page.screenshot({ path: "./screen/signedin.png" });

    for (let i = start; i <= end; i++) {
        console.log(`Trying to solve prob. ${i}...`);
        let result = await submit(page, { prob: i });
        if (result) {
            console.log(`Prob. ${i} Submitted. :)`);
            let span = (8 + Math.random() * 6) * 60 * 1000;
            console.log(`Wait for ${(span / 1000).toFixed(1)} seconds before next operation.`);
            await sleep(span);
        } else {
            console.log(`Sorry, I cannot find solution of prob. ${i} :(`);
            console.log(`Wait for 10 seconds before next operation.`);
            await sleep(10 * 1000);
        }
    }

    await page.goto("https://tioj.ck.tp.edu.tw/submissions");
    if (SHOT) await page.screenshot({ path: "./screen/submissions.png" });

    await browser.close();
}

function cur_user() {
    return {
        email: "test@ioinformatics.org",
        username: "tester_101",
        nickname: "Tester 101",
        password: "Tester 101",
        name: "IOI.JQBPZK",
        school: "IOI <ioinformatics.org>",
        graduation: "101",
    };
}
function gen_user() {
    let u = random_string(6);
    return {
        email: u + "@ioinformatics.org",
        username: "ioi." + u,
        nickname: u.toUpperCase(),
        password: u.split("").reverse().join(""),
        name: "IOI." + u.toUpperCase(),
        school: "IOI <ioinformatics.org>",
        graduation: String(100 + Math.floor(10 * Math.random())),
    };
}

async function signup(page, { email, username, nickname, password, name, school, graduation }) {
    await page.goto("https://tioj.ck.tp.edu.tw/users/sign_up");
    await page.$eval("#user_email", (el, value) => (el.value = value), email);
    await page.$eval("#user_username", (el, value) => (el.value = value), username);
    await page.$eval("#user_nickname", (el, value) => (el.value = value), nickname);
    await page.$eval("#user_password", (el, value) => (el.value = value), password);
    await page.$eval("#user_password_confirmation", (el, value) => (el.value = value), password);
    await page.$eval("#user_name", (el, value) => (el.value = value), name);
    await page.$eval("#user_school", (el, value) => (el.value = value), school);
    await page.$eval("#user_gradyear", (el, value) => (el.value = value), graduation);
    await page.$eval("input[type=submit]", (el) => el.click());
}

async function signin(page, { username, password, remember }) {
    await page.goto("https://tioj.ck.tp.edu.tw/users/sign_in");
    await page.$eval("#user_username", (el, value) => (el.value = value), username);
    await page.$eval("#user_password", (el, value) => (el.value = value), password);
    if (remember) await page.$eval("#user_remember_me", (el) => el.click());
    await page.$eval("input[type=submit]", (el) => el.click());
}

async function submit(page, { prob }) {
    if (!prob) return false;
    await page.goto(`https://tioj.ck.tp.edu.tw/problems/${prob}/submissions/new`);
    if (SHOT) await page.screenshot({ path: "./screen/submit.png" });

    let { exists, code } = await get_code(prob);

    if (!exists) return false;

    if (SHOW_CODE) console.log(`Code of Prob.${prob}: \n`, code, "\n");

    await page.$eval("textarea", (el, value) => (el.value = value), code);
    await page.$eval("input[type=submit]", (el) => el.click());
    return true;
}

async function get_code(prob) {
    const folder = "./solutions/";
    let filenames = fs.readdirSync(folder);
    let checker = filenames.filter((filename) => filename.includes(String(prob)));
    if (!checker.length) return { exists: false, code: null };
    let code = String(fs.readFileSync(folder + checker[0])).replace(/\/\*[\s\S]*?\*\/|([^\\:]|^)\/\/.*$/gm, "");
    return {
        exists: true,
        code: code.split("\n").reduce((a, b) => {
            return a + "\n".repeat(Math.floor(1 + Math.random() * 3)) + "    ".repeat(Math.floor(Math.random() * 5)) + b.trim();
        }, ""),
    };
}

async function check_database() {
    const folder = "./solutions/";
    let filenames = fs.readdirSync(folder);
    let count = 0;
    for (let i = 1001; i <= 3000; i++) {
        let checker = filenames.filter((filename) => filename.includes(String(i)));
        if (checker) count++;
    }
    return count;
}

function sleep(ms = 1000) {
    return new Promise((r) => {
        setTimeout(r, ms);
    });
}

function random_string(length = 16) {
    var result = "";
    var characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    var charactersLength = characters.length;
    for (var i = 0; i < length; i++) {
        result += characters.charAt(Math.floor(Math.random() * charactersLength));
    }
    return result;
}
