class Project {
    constructor(id, title, tech, description, link, demoLink) {
        this.id = id;
        this.title = title;
        this.tech = tech;
        this.description = description;
        this.link = link;
        this.demoLink = demoLink;
    }
    getSummary() {
        return `${this.title}: ${this.description}`;
    }
}

class FeaturedProject extends Project {
    constructor(id, title, tech, description, link, demoLink, badge) {
        super(id, title, tech, description, link, demoLink);
        this.badge = badge;
    }
}

const projects = [
    new FeaturedProject(1, "Online Course Management System", ["Java", "MySQL"], "Manages courses, students and enrolments in one system.", "contact.html", "index.html", "Featured"),
    new FeaturedProject(2, "Personal Expense Tracker", ["Java"], "Records daily expenses and summarises spending.", "contact.html", undefined, "Practice"),
    new Project(3, "Binary Tree Traversals", ["Java", "DSA"], "Shows inorder, preorder and postorder traversal.", "contact.html", undefined),
    new Project(4, "Portfolio Website", ["HTML", "CSS", "JavaScript"], "A three-page personal portfolio with interactive features.", "index.html", "index.html"),
    new Project(5, "Bakery Order Calculator", ["HTML", "CSS", "JavaScript"], "Calculates item quantities, discounts and delivery charges.", "../landing-page/landing.html", undefined)
];

const projectBody = document.getElementById("project-body");
const projectCount = document.getElementById("project-count");
const techFilter = document.getElementById("tech-filter");

function loadProjects() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (projects.length === 0) {
                reject("No projects available.");
            } else {
                resolve(projects);
            }
        }, 1500);
    });
}

function fillTechOptions() {
    const techs = [...new Set(projects.reduce((all, project) => all.concat(project.tech), []))];
    techs.forEach(tech => {
        const option = document.createElement("option");
        option.value = tech;
        option.innerHTML = tech;
        techFilter.appendChild(option);
    });
}

function showProjects(list) {
    projectBody.innerHTML = "";
    list.forEach(project => {
        const row = document.createElement("tr");
        const titleCell = document.createElement("td");
        const techCell = document.createElement("td");
        const descriptionCell = document.createElement("td");
        const linkCell = document.createElement("td");
        titleCell.innerHTML = project.title;
        techCell.innerHTML = project.tech.join(", ");
        descriptionCell.innerHTML = project.getSummary();
        const link = document.createElement("a");
        link.href = project.demoLink ?? project.link ?? "#";
        link.innerHTML = project.demoLink ?? "Not available";
        linkCell.appendChild(link);
        row.append(titleCell, techCell, descriptionCell, linkCell);
        projectBody.appendChild(row);
    });
    projectCount.innerHTML = `Showing ${list.length} of ${projects.length} projects`;
}

function showFeatured() {
    const container = document.getElementById("top-projects");
    container.innerHTML = "";
    projects.filter(project => project instanceof FeaturedProject).slice(0, 2).forEach(project => {
        const card = document.createElement("article");
        card.className = "card";
        const badge = document.createElement("span");
        badge.className = "badge";
        badge.innerHTML = project.badge;
        const title = document.createElement("h3");
        title.innerHTML = project.title;
        const description = document.createElement("p");
        description.innerHTML = project.description;
        const link = document.createElement("a");
        link.href = project.link;
        link.innerHTML = "Ask me about it";
        card.append(badge, title, description, link);
        container.appendChild(card);
    });
}

function filterProjects() {
    const searchText = document.getElementById("project-search").value.toLowerCase();
    const selectedTech = techFilter.value;
    const filtered = projects.filter(project => project.title.toLowerCase().includes(searchText) && (selectedTech === "all" || project.tech.includes(selectedTech)));
    showProjects(filtered);
}

async function startProjects() {
    projectCount.innerHTML = "Loading projects...";
    try {
        await loadProjects();
        fillTechOptions();
        showProjects(projects);
        showFeatured();
        const titles = projects.map(project => project.title);
        Promise.resolve(titles).then(items => {
            document.getElementById("projects-intro").innerHTML = `Explore ${items.length} projects built while learning web development and programming.`;
        }).catch(() => {
            document.getElementById("project-error").innerHTML = "Could not show project titles.";
        });
    } catch (error) {
        document.getElementById("project-error").innerHTML = error;
        projectCount.innerHTML = "Projects could not be loaded.";
    }
}

startProjects();
