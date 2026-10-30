function welcomeVisitor() {
    const name = document.getElementById("visitor-name").value.trim();
    const message = document.getElementById("welcome-message");
    if (name === "") {
        message.innerHTML = "Please enter your name first.";
    } else {
        message.innerHTML = `Welcome, ${name}!`;
    }
}

function changeTheme() {
    const body = document.body;
    const button = document.getElementById("theme-button");
    if (button.innerHTML === "Dark mode") {
        body.style.backgroundColor = "#20242b";
        body.style.color = "#f5f5f5";
        button.innerHTML = "Light mode";
    } else {
        body.style.backgroundColor = "";
        body.style.color = "";
        button.innerHTML = "Dark mode";
    }
}

function toggleSkills() {
    const list = document.getElementById("skills-list");
    const button = document.getElementById("skills-button");
    if (list.style.display === "none") {
        list.style.display = "block";
        button.innerHTML = "Hide";
    } else {
        list.style.display = "none";
        button.innerHTML = "Show";
    }
}

async function loadRepositories() {
    const list = document.getElementById("repository-list");
    const error = document.getElementById("github-error");
    list.innerHTML = "";
    error.innerHTML = "Loading repositories...";
    try {
        const response = await fetch("https://api.github.com/users/samriddhisharma07/repos");
        if (response.status !== 200) {
            throw new Error(`Request failed with status ${response.status}`);
        }
        const data = await response.json();
        data.forEach(repo => {
            const item = document.createElement("li");
            item.innerHTML = repo.name;
            list.appendChild(item);
        });
        error.innerHTML = data.length === 0 ? "No public repositories found." : "";
    } catch (e) {
        error.innerHTML = "Could not load repositories. Please check your internet connection.";
    }
}
