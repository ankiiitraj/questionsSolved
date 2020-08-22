'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readline() {
    return inputString[currentLine++];
}
function readarr() {
    let arr = inputString[currentLine++];
    arr  = arr.split(' ').map(function(item){
        return parseInt(item);
    });
    return arr;
}


function main() {
    let temp = readline();
    let n = parseInt(temp.split(' ')[0]);
    let t = parseInt(temp.split(' ')[1]);
    var a = readarr(), b = readarr();
    let copyA = clone(a);
    setup(n, t, copyA, b);
    for(let j = 0; j < totalGenerations; ++j){
        draw(n, t, copyA, b);
    }
    let res = population.getBest();
    for (let i = 0; i < res.length; i++) {
        const temp = a[res[i].second];
        a[res[i].second] = a[res[i].first];
        a[res[i].first] = temp;
    }
    for(let i = 0; i < a.length; ++i)
        process.stdout.write("" + a[i] + " ");
    process.stdout.write("\n");
    for(let i = 0; i < a.length; ++i)
        process.stdout.write("" + b[i] + " ");
    process.stdout.write("\n");
}

function clone(a){
    let new_a = JSON.stringify(a);
    new_a = JSON.parse(new_a);
    return new_a;
}

function rand(l, r){
    return (Math.floor(Math.random()*1000000))%r + l;
}

function newpair(num){
    let pair;
    let first = rand(0, num), second = rand(0, num);
    pair = {
        first, second
    };
    return pair;
}

function map(x, in_min, in_max, out_min, out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

function calc(genes, a, B){
    let A = clone(a);
    for (let i = 0; i < genes.length; i++) {
        let temp = a[genes[i].first];
        a[genes[i].first] = a[genes[i].second];
        a[genes[i].second] = temp;
    }
    let score = 0;
    for (let i = 0; i < A.length; i++) {
        score = score + a[i]*B[i];
    }
    return score;
}

class DNA {
    constructor(num, n) {
        // The genetic sequence
        this.genes = [];
        this.fitness = 0;
        for (let i = 0; i < num; i++) {
            this.genes[i] = newpair(n);
        }
    }

    calcFitness(A, B, t) {
        let score = calc(this.genes, A, B);
        this.fitness = 1/(Math.abs(score - t) / A.length + 0.01);
    }

    // Crossover
    crossover(partner) {
        let child = new DNA(this.genes.length);

        let midpoint = rand(1, this.genes.length);

        for (let i = 0; i < this.genes.length; i++) {
            if (i > midpoint) 
                child.genes[i] = this.genes[i];
            else 
                child.genes[i] = partner.genes[i];
        }
        return child;
    }

    getPhrase() {
        return this.genes;
    }

    // Based on a mutation probability, picks a new random character
    mutate(mutationRate, n) {
        for (let i = 0; i < this.genes.length; i++) {
            if (Math.random() < mutationRate) {
                this.genes[i] = newpair(n);
            }
        }
    }
}

class Population {
    constructor(m, p, n, t, A, B) {  
      this.population; // Array to hold the current population
      this.matingPool; // ArrayList which we will use for our "mating pool"
      this.generations = 0; // Number of generations
      this.mutationRate = m;
  
      this.population = [];
      for (let i = 0; i < p; i++) {
        this.population[i] = new DNA(100, n);
      }
      this.matingPool = [];
      this.calcFitness(A, B, t);
    }
  
    // Fill our fitness array with a value for every member of the population
    calcFitness(A, B, t) {
      for (let i = 0; i < this.population.length; i++) {
        this.population[i].calcFitness(A, B, t);
      }
    }
  
    // Create a new generation
    generate(n) {
      // Refill the population with children from the mating pool
      let maxFitness = -1;
      for (let i = 0; i < this.population.length; i++) {
        maxFitness = Math.max(maxFitness, this.population[i].fitness);
    }
    let new_pop = [];
    for (let i = 0; i < this.population.length; i++) {
        let partnerA = this.acceptReject(maxFitness);
        let partnerB = this.acceptReject(maxFitness);
        let child = partnerA.crossover(partnerB);
        child.mutate(this.mutationRate, n);
        new_pop.push(child);
    }
    this.population = new_pop;
    console.log(this.population);
      this.generations++;
    }
  
    acceptReject(maxFitness){
        let cnt = 0;
        while(cnt < 100){
            let idx = rand(0, this.population.length);
            let fitness = this.population[idx].fitness;
            var prob = rand(0, maxFitness);
            if(fitness > prob){
                return this.population[idx];
            }
            cnt++;
        }
        return null;
    }

    getBest() {
      return this.best;
    }
  
    // Compute the current "most fit" member of the population
    evaluate() {
      let worldrecord = -1;
      let index = 0;
      for (let i = 0; i < this.population.length; i++) {
        if (this.population[i].fitness > worldrecord) {
          index = i;
          worldrecord = this.population[i].fitness;
        }
      }
  
      this.best = this.population[index].getPhrase();
    }
    getGenerations() {
      return this.generations;
    }
}

let popmax;
let mutationRate;
let population;
let totalGenerations;

function setup(n, t, A, B) {
  popmax = 100;
  mutationRate = 0.01;
  totalGenerations = 100;
  population = new Population(mutationRate, popmax, n, t, A, B);
}

function draw(n, t, A, B) {
  //Generate mating pool
//   population.naturalSelection();
  //Create next generation
  population.generate(n);
  // Calculate fitness
  population.calcFitness(A, B, t);
  population.evaluate();
}